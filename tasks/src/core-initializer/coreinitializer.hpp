#ifndef COREINITIALIZER_H_
#define COREINITIALIZER_H_

#include "AbstractCoreInitializer.hpp"

class CoreInitializer: public AbstractCoreInitializer
{
    public:
        CoreInitializer() ;
        ~CoreInitializer() ;
    public:
        void initDatabases()  override;
        std::shared_ptr<TaskStorage> getTaskStorage() const override ;

    private:
        std::shared_ptr<TaskStorage> mTasksStorage;
};



#endif