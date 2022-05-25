#include "Observer.hpp"

class XYZ : public Subject 
{
    private: 
        int var1, var2, var3, var4, var5;

    public:
        XYZ() = default;
        void Setvar(int var1_, int var2_, int var3_, int var4_, int var5_) {
            this->var1 = var1_; 
            this->var2 = var2_;
            this->var3 = var3_;
            this->var4 = var4_;
            this->var5 = var5_;

            notify(); 
        }

        int var1_() const { 
            return var1; 
            }
        int var2_() const { 
            return var2; 
            }
        int var3_() const { 
            return var3; 
            }
        int var4_() const { 
            return var4; 
            }
        int var5_() const { 
            return var5; 
            }
}; 


class Forecast: public Observer 
{ 
    private:
        XYZ subject;

    public: 
        explicit Forecast(XYZ& s) : subject(s) { subject.attach(*this); }
        ~Forecast() override { subject.detach(*this); }
        void update(Subject& theChangedSubject) override
        {
            if (&theChangedSubject == &subject) {
                show_winner();
            }
        }

        void show_winner() const
        {
            int var1 = subject.var1_(); 
            int var2 = subject.var2_(); 
            int var3 = subject.var3_(); 
            int var4 = subject.var4_();
            int var5 = subject.var5_();

            std::cout << "las variables son " << var1 << " , "  << var2 << " , " << var3 << std::endl;           
        }
};

class Current: public Observer 
{
    private:
        XYZ subject;

    public: 
        explicit Current(XYZ& s) : subject(s) { subject.attach(*this); }
        ~Current() override { subject.detach(*this); }
        void update(Subject& theChangedSubject) override
        {
            if (&theChangedSubject == &subject) {
                show_winner();
            }
        }
        void show_winner() const
        {
            int var1 = subject.var1_(); 
            int var2 = subject.var2_(); 
            int var3 = subject.var3_(); 
            int var4 = subject.var4_();
            int var5 = subject.var5_();

            std::cout << "las variables de current son " << var1 << " ; " << var2 << " ; " << var3 << std::endl; 
        }

};


class Stadistics: public Observer 
{ 
    private:
        XYZ& subject;

    public: 
        explicit Stadistics(XYZ& s) : subject(s) { subject.attach(*this); }
        ~Stadistics() override { subject.detach(*this); }
        void update(Subject& theChangedSubject) override
        {
            if (&theChangedSubject == &subject) {
                show_winner();
            }
        }
        void show_winner() const
        {
            int var1 = subject.var1_(); 
            int var2 = subject.var2_(); 
            int var3 = subject.var3_(); 
            int var4 = subject.var4_();
            int var5 = subject.var5_();

            std::cout << "las variables de stadistics son " << var1 << " ; " << var2 << " ; " << var3 << std::endl; 
        }

};