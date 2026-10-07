#pragma once
#include <ostream>
#include <string>

class processData
{
public:
    processData(int PID, const std::string& name, const std::string& Desc)
        : PID_(PID), name_(name), Desc_(Desc)
    {
    }
    bool operator==(const processData& other) const {
        return PID_ == other.PID_;
    }

    void set_PID(int PID){
        PID_ = PID;
    }

    int get_PID() const{
        return PID_;
    }

    void set_name(const std::string& name){
        name_ = name;
    }

    std::string get_name() const{
        return name_;
    }

    void set_desc(const std::string& desc){
        Desc_ = desc;
    }

    std::string get_desc() const{
        return Desc_;
    }

    friend std::ostream& operator<<(std::ostream& out, const processData& d)
    {
        return out << "PID: " << d.PID_
                   << " Name: " << d.name_
                   << " Desc: " << d.Desc_;
    }

private:
    int PID_;
    std::string name_;
    std::string Desc_;
};

