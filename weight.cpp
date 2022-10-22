#include <iostream>

using namespace std;
double pre_process(double oth_init, double oth_score, double oth_all, double oth_before_out, double oth_after_out)
{
    double all_except_oth = oth_all - oth_init * oth_score;
    int init2 = (oth_after_out * all_except_oth) / ((1 - oth_after_out) * oth_score);
    return init2 - oth_init;
}

//检查x是否合法：对应学分，除it以外的分母值，期望输出
bool check(double x, double it_score, double all_except_it, double it_out)
{
    double y = (x * it_score / (x * it_score + all_except_it));
    return y > it_out;
}

//对应学分，除it以外的分母值，期望输出， 它的取值范围
void bs(double it_score, double all_except_it, double it_out, double low, double great)
{
    double l = low, r = great;
    while (r - l > 1e-4)
    {
        double mid = (r + l) / 2;
        if (check(mid, it_score, all_except_it, it_out)) r = mid;
        else l = mid;
    }
    double res1 = r;

    l = low, r = great;
    while (r - l > 1e-4)
    {
        double mid = (r + l) / 2;
        if (check(mid, it_score, all_except_it, it_out)) l = mid;
        else r = mid;
    }
    double res2 = r;
    double res = (res1 + res2) / 2;
    if (check(res, it_score, all_except_it, it_out)) 
        cout << "Yes!  " <<  res << endl;
    else cout << "No" << res << endl;
}

int main()
{
    //计算part1最多能+多少 计算part2最多能-多少
    double oth_init, oth_score, oth_all, oth_before_out, oth_after_out;
    cin >> oth_init >> oth_score >> oth_all >> oth_before_out >> oth_after_out;
    double dx = pre_process();

    //原来1表的值， 学分， 2表总占比， 输出期望
    double it_init, it_score, it_all, it_out;
    cin >> it_init >> it_score >> it_all >> it_out;

    double all_except_it = it_all - it_init * it_score;  //2表除了it以外的占比
    bs(it_score, all_except_it, it_out, it_init, it_init + dx);


    return 0;
}