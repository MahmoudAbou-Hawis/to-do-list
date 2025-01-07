#ifndef STORAGE_H_
#define STORAGE_H_

#include <db_cxx.h>
#include <dbstl_map.h>
#include <memory>
#include <vector>
#include <stdexcept>

namespace prstorage
{
    template <
        typename Element,
        typename Marshaller>
    class Storage :  public std::enable_shared_from_this<Storage<Element, Marshaller>>     
    {
    public:
        using element = Element;
        using key = decltype(get_id(std::declval<Element>()));
        Storage(std::shared_ptr<Db> db,std::shared_ptr<DbEnv> env);

    public:
        std::vector<Element> getAllElements() const ;
        Element get(const key &key) const ;
        bool add(const Element &elem) const ; 
        bool remove(const key &key) const ;
        bool update(const Element &elem) const ;
        std::shared_ptr<Storage<Element, Marshaller>> getSharedObject() ;

    private:
        mutable dbstl::db_map<key, element> mElements;
        mutable std::shared_ptr<DbEnv> mEnv;
        std::shared_ptr<Db>  mDb;
    };

    template <typename Element,
              typename Marshaller>
    prstorage::Storage<Element, Marshaller>::Storage(std::shared_ptr<Db> db,std::shared_ptr<DbEnv> env)
        : mElements(db.get(), env.get()), mEnv(std::move(env)) , mDb(std::move(db))
    {
        auto inst = dbstl::DbstlElemTraits<Element>::instance();
        inst->set_size_function(&Marshaller::size);
        inst->set_restore_function(&Marshaller::restore);
        inst->set_copy_function(&Marshaller::store);
    }


    template <
        typename Element,
        typename Marshaller>
    bool prstorage::Storage<Element, Marshaller>::add(const Element &elem) const
    {
        if (auto [it, res] = mElements.insert(std::make_pair(get_id(elem), elem)); res)
        {
            return true;
        }
        return false;
    }

    template <typename Element,
              typename Marshaller>
    typename prstorage::Storage<Element, Marshaller>::element
    prstorage::Storage<Element, Marshaller>::get(const key &key) const
    {
        if (auto iter = mElements.find(key); iter != mElements.end())
        {
            return (*iter).second;
        }
        throw std::range_error("element not found");
    }

    template <typename Element,
              typename Marshaller>
    bool prstorage::Storage<Element, Marshaller>::update(const Storage::element &elem) const
    {
        if (auto iter = mElements.find(get_id(elem)); iter != mElements.end())
        {
            mElements[get_id(elem)] = elem;
            return true;
        }
        return false;
    }

    template <typename Element,
              typename Marshaller>
    bool prstorage::Storage<Element, Marshaller>::remove(const Storage::key &key) const
    {
        if (auto iter = mElements.find(key); iter != mElements.end())
        {
            mElements.erase((*iter).first);
            return true;
        }
        return false;
    }

    template <typename Element, typename Marshaller>
    std::shared_ptr<Storage<Element, Marshaller>> Storage<Element, Marshaller>::getSharedObject()
    {
        return this->shared_from_this();
    }

    template <typename Element, typename Marshaller>
    std::vector<typename prstorage::Storage<Element, Marshaller>::element>
    prstorage::Storage<Element, Marshaller>::getAllElements() const
    {
        std::vector<element> elements;
        for (auto iter = mElements.begin(); iter != mElements.end(); iter++)
        {
            elements.push_back((*iter).second);
        }
        return elements;
    }
}
#endif // STORAGE_H_`