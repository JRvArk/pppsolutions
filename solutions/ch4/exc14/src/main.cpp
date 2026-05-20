#include <iostream>
#include <string>
#include <vector>

void print_weekday_values(const std::string& day_of_week, const std::vector<int>& values)
{
    std::cout << day_of_week << ": ";
    for (int value : values)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
    std::cout << "Sum of " << day_of_week;
    int sum = 0;
    for (int value : values)
    {
        sum += value;
    }
    std::cout << " values: " << sum << '\n';
}

int main()
{
    std::vector<int> monday_values{};
    std::vector<int> tuesday_values{};
    std::vector<int> wednesday_values{};
    std::vector<int> thursday_values{};
    std::vector<int> friday_values{};
    std::vector<int> saturday_values{};
    std::vector<int> sunday_values{};

    std::string day_of_week{};
    int value{};
    int rejected_values_count = 0;

    while (std::cin >> day_of_week)
    {
        if (!(std::cin >> value))
        {
            std::cin.clear();
            std::string skip;
            std::cin >> skip;
            ++rejected_values_count;
            continue;
        }
        if (day_of_week == "Monday" || day_of_week == "Mon" || day_of_week == "mon" ||
            day_of_week == "MON" || day_of_week == "monday")
        {
            monday_values.push_back(value);
        }
        else if (day_of_week == "Tuesday" || day_of_week == "Tue" || day_of_week == "tue" ||
                 day_of_week == "TUE" || day_of_week == "tuesday")
        {
            tuesday_values.push_back(value);
        }
        else if (day_of_week == "Wednesday" || day_of_week == "Wed" || day_of_week == "wed" ||
                 day_of_week == "WED" || day_of_week == "wednesday")
        {
            wednesday_values.push_back(value);
        }
        else if (day_of_week == "Thursday" || day_of_week == "Thu" || day_of_week == "thu" ||
                 day_of_week == "THU" || day_of_week == "thursday")
        {
            thursday_values.push_back(value);
        }
        else if (day_of_week == "Friday" || day_of_week == "Fri" || day_of_week == "fri" ||
                 day_of_week == "FRI" || day_of_week == "friday")
        {
            friday_values.push_back(value);
        }
        else if (day_of_week == "Saturday" || day_of_week == "Sat" || day_of_week == "sat" ||
                 day_of_week == "SAT" || day_of_week == "saturday")
        {
            saturday_values.push_back(value);
        }
        else if (day_of_week == "Sunday" || day_of_week == "Sun" || day_of_week == "sun" ||
                 day_of_week == "SUN" || day_of_week == "sunday")
        {
            sunday_values.push_back(value);
        }
        else
        {
            ++rejected_values_count;
        }
    }
    std::cout << "Rejected values: " << rejected_values_count << '\n';
    print_weekday_values("Monday", monday_values);
    print_weekday_values("Tuesday", tuesday_values);
    print_weekday_values("Wednesday", wednesday_values);
    print_weekday_values("Thursday", thursday_values);
    print_weekday_values("Friday", friday_values);
    print_weekday_values("Saturday", saturday_values);
    print_weekday_values("Sunday", sunday_values);
}
