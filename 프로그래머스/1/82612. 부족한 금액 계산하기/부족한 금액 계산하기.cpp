using namespace std;

long long solution(int price, int money, int count)
{
    long long lack = 1LL * price * count * (count + 1) / 2 - money;
    if (lack <= 0) {
        return 0;
    }
    return lack;
}