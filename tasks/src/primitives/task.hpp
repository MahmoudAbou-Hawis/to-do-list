#ifndef TASK_H
#define TASK_H

#include <string>
#include <string_view>

class Task {

    public:
        template <typename S, 
                    class = typename std::enable_if<
                    std::is_constructible<std::string, S>::value>::type>
        Task(S &&name, S &&notes, S &&email, S &&date, S &&time, int originalIndex, 
                bool status, bool completed);

        Task() =default;

    public:
        void name(std::string name);
        void notes(std::string notes);
        void email(std::string email);
        void date(std::string date);
        void time(std::string time);
        void originalIndex(int originalIndex);
        void status(bool status);
        void completed(bool completed);

    public:
        std::string_view name() const noexcept;
        std::string_view notes() const noexcept;
        std::string_view email() const noexcept;
        std::string_view date() const noexcept;
        std::string_view time() const noexcept;
        int originalIndex() const noexcept;
        bool status() const noexcept;
        bool completed() const noexcept;

    private:
        std::string mName;
        std::string mNotes;
        std::string mEmail;
        std::string mDate;
        std::string mTime;
        int mOriginalIndex;
        bool mCompleted;
        bool mStatus;
};

template <typename S, class>
Task::Task(S &&name, S &&notes, S &&email, S &&date, S &&time, int originalIndex, 
        bool status, bool completed) :
    mName(std::forward<S>(name)),
    mNotes(std::forward<S>(notes)),
    mEmail(std::forward<S>(email)),
    mDate(std::forward<S>(date)),
    mTime(std::forward<S>(time)),
    mOriginalIndex(originalIndex),
    mStatus(status),
    mCompleted(completed)
{

}




#endif