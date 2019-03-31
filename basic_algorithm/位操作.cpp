unsigned short ros(unsigned short val, int size)//循环左移
{
  unsigned short res = val << size;
  res |= val >> (16 - size);
  return res;
}
unsigned short ror(unsigned short val,int size){
  unsigned short res=val>>size;
  res = res|(val<<16-size);
  return res;
}