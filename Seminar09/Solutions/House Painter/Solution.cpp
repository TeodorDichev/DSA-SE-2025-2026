// Tables: DPb[i] - минималната цена за боядисване на къщите от 0 до i, ако последната е синя
// Tables: DPr[i] - минималната цена за боядисване на къщите от 0 до i, ако последната е червена
// Tables: DPg[i] - минималната цена за боядисване на къщите от 0 до i, ако последната е зелена
// Rec: DPr[i] = costR[i] +  min(DPg[i-1], DPb[i-1])
// Rec: DPg[i] = costG[i] +  min(DPr[i-1], DPb[i-1])
// Rec: DPb[i] = costB[i] +  min(DPg[i-1], DPr[i-1])

size_t Solve(vector<int> costR, vector<int> costG, vector<int> costB)
{
    vector<int> dpr; vector<int> dpb; vector<int> dpg;
    dpr.push_back(costR[0]);
    dpg.push_back(costG[0]);
    dpb.push_back(costB[0]);

    for(size_t i=1; i < n; i++)
    {
        dpr.push_back(costR[i] + min(dpb[i-1],dpg[i-1]));
        dpg.push_back(costG[i] + min(dpb[i-1],dpr[i-1]));
        dpb.push_back(costB[i] + min(dpr[i-1],dpg[i-1]));
    }

    return min(dpr[n], dpg[n], dpb[n]);
}