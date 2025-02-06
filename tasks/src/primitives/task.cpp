#include "task.hpp"

void Task::name(std::string name)
{
    mName = std::move(name);
}

void Task::notes(std::string notes)
{
    mNotes = std::move(notes);
}

void Task::email(std::string email)
{
    mEmail = std::move(email);
}

void Task::date(std::string date)
{
    mDate = std::move(date);
}

void Task::time(std::string time)
{
    mTime = std::move(time);
}

void Task::originalIndex(int originalIndex)
{
    mOriginalIndex = originalIndex;
}

void Task::status(bool status)
{
    mStatus = status;
}

void Task::completed(bool completed)
{
    mCompleted = completed;
}

void Task::id(std::string id)
{
    mId = id;
}

std::string_view Task::name() const noexcept
{
    return static_cast<std::string_view>(mName);
}

std::string_view Task::notes() const noexcept
{
    return static_cast<std::string_view>(mNotes);
}

std::string_view Task::date() const noexcept
{
    return static_cast<std::string_view>(mDate);
}   

std::string_view Task::time() const noexcept
{
    return static_cast<std::string_view>(mTime);
}

int Task::originalIndex() const noexcept
{
    return mOriginalIndex;
}

bool Task::status() const noexcept
{
    return mStatus;
}

bool Task::completed() const noexcept
{
    return mCompleted;
}

std::string_view Task::id() const noexcept
{
    return static_cast<std::string_view>(mId);
}

std::string_view Task::email() const noexcept
{
    return static_cast<std::string_view>(mEmail);
}

