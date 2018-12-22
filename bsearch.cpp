bool validate(ll val)
{
  // some logic based on whether the given condition is true or not
}
bool check(ll val,ll key)
{
  if(validate(val),key)
  {
  // logic for eliminating the half 
  return true;
  }
  else  return false;

}

ll bsearch(ll l , ll r ,ll key)
{
  ll mid=(l+r)>>2;
  if(l==r)
  return l;
 if(check(mid,key))
  l=mid;
  else r=mid-1;
  bsearch(l,r,key);
}
