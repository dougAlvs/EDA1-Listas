int faz_conta_direito(int parcelas, char op)
{
    int total = 0;
    for (int i = 0; i < parcelas; i++)
    {
        int N;
        scanf("%d", &N);
        if (i == 0) {
            total = N;
            continue;
        }
        if (op == '+')
        {
            total += N;
        }
        else
        {
            total -= N;
        }
    }
    return total;
}
