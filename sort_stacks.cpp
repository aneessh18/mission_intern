void SortedStack :: sort()
{
   //Your code here
   stack <int> helper;
   if(!s.empty())
   {
       helper.push(s.top());
       s.pop();
       while(!s.empty() && !helper.empty())
       {
           if(s.top()<=helper.top())
           {
               helper.push(s.top());
               s.pop();
           }
           else
           {
               vector <int> keeper;
               while( !helper.empty() && s.top()>helper.top())
               {
                   keeper.push_back(helper.top());
                   helper.pop();
               }
               helper.push(s.top());
               s.pop();
               for( auto itr=keeper.rbegin();itr!=keeper.rend();itr++)
               {
                   helper.push(*itr);
               }
           }
       }
   }
   while(!helper.empty())
   {
       s.push(helper.top());
       helper.pop();
   }
}
