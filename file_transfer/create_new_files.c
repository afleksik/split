int create_files(int n)
{
    for(int i = 0; i < n; i++)
    {
        ofstream fout(string("file") + to_string(i));
        fout.close();
    }
    return 0;
}