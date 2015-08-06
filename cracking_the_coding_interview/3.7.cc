class CatDogAsylum {
    queue<int> dogs_;
    queue<int> cats_;
    int id_;

    void push(int num)
    {
        if (num < 0)
        {
            cats_.push(id_);
            cats_.push(num);
        }
        else
        {
            dogs_.push(id_);
            dogs_.push(num);
        }
        ++id_;
    }

    int popAny()
    {
        int num = 0;
        if (dogs_.empty())
        {
            return popCat();
        }
        else if (cats_.empty())
        {
            return popDog();
        }
        else
        {
            if (dogs_.front() < cats_.front())
            {
                return popDog();
            }
            else
            {
                return popCat();
            }
        }
        return num;
    }

    int popDog()
    {
        int num;
        dogs_.pop();
        num = dogs_.front();
        dogs_.pop();
        return num;
    }

    int popCat()
    {
        int num;
        cats_.pop();
        num = cats_.front();
        cats_.pop();
        return num;
    }

public:
    vector<int> asylum(vector<vector<int> > ope) {
        dogs_ = queue<int>();
        cats_ = queue<int>();
        id_ = 0;
        vector<int> v;
        for (int i = 0; i < ope.size(); ++i)
        {
            if (ope[i][0] == 1)
            {
                push(ope[i][1]);
            }
            else if (ope[i][0] == 2)
            {
                if (ope[i][1] == 0 && (!cats_.empty() || !dogs_.empty()))
                    v.push_back(popAny());
                else if (ope[i][1] == 1 && !dogs_.empty())
                    v.push_back(popDog());
                else if (ope[i][1] == -1 && !cats_.empty())
                    v.push_back(popCat());
            }
        }
        return v;
    }
};
