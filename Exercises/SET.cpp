#include <iostream>
#include <vector>

template<class type>
class SET
{
    private:
        std::vector<type> new_set;

    public:
        SET(std::vector<type> new_set)
        {   
            this->new_set = new_set;
        }

        int cardinal()
        {
            int count = 0;
            for (int i = 0; i != new_set.size(); i++)
                count += 1;

            return count;
        }

        bool show()
        {
            if (this->cardinal() == 0)
            {
                std::cout << "Empty set\n";
                return false;
            }

            for (int i = 0; i != new_set.size(); i++)
                std::cout << new_set[i] << "\n";

            return true;
        }

        bool operator==(SET b)
        {
            if(this->cardinal() == b.cardinal())
                return true;
            else
                return false;
        }

        bool check_if_subset(SET other)
        {
            int count = 0;
            if (this->cardinal() < other.cardinal())
            {
                for (int i = 0; i != this->new_set.size(); i++)
                    for(int j = 0; j != other.new_set.size(); j++)
                    {
                        if (this->new_set[i] == other.new_set[j])
                            count++;
                        else
                            continue;
                    }
            }
            if (count == this->cardinal())
                return true;
            else
                return false;

            return true;
        }

        bool check_if_superset(SET other)
        {
            bool output = this->check_if_subset(other);

            if (output)
                return false;
            else
                return true;
        }

        SET intersect(SET other)
        {
            std::vector<type> a;
            SET output = a;

            for (int i = 0; i != this->new_set.size(); i++)
                for (int j = 0; j != other.new_set.size(); j++)
                {
                    if (this->new_set[i] == other.new_set[j])
                        output.new_set.push_back(this->new_set[i]);
                }

                return output;
        }

        SET uni(SET other)
        {
            SET output = this->intersect(other);

            for (int i = 0; i != this->new_set.size(); i++)
                if (this->new_set[i] != output.new_set[i])
                    output.new_set.push_back(this->new_set[i]);

            for (int i = 0; i != other.new_set.size(); i++)
                if (other.new_set[i] != output.new_set[i])
                    output.new_set.push_back(other.new_set[i]);

            return output;
        }

        SET complement(SET other)
        {
            std::vector<type> a;
            SET output = a, inters = this->intersect(other), un = this->uni(other);

            if (inters.cardinal() == 0)
            {
                output = this->new_set;
                return output;
            }
            else
            {
                for (int i = 0; i != this->new_set.size(); i++)
                    if (this->new_set[i] != inters.new_set[i])
                        output.new_set.push_back(this->new_set[i]);
            }

            return output;
        }

        
};      



