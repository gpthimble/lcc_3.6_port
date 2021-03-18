unsigned int divu(unsigned int a, unsigned int b)
{
  unsigned int bit = 1;
  unsigned int res = 0;
  while (b < a && bit && !(b & (1L<<31)))
    {
      b <<=1;
      bit <<=1;
    }
  while (bit)
    {
      if (a >= b)
	{
	  a -= b;
	  res |= bit;
	}
      bit >>=1;
      b >>=1;
    }
  return res;
}

unsigned int remu(unsigned int a, unsigned int b)
{ 
    unsigned int bit = 1;
    unsigned int res = 0;

    while (b < a && bit && !(b & (1L<<31)))
    {
      b <<=1;
      bit <<=1;
    }
  while (bit)
    {
      if (a >= b)
	{
	  a -= b;
	  res |= bit;
	}
      bit >>=1;
      b >>=1;
    }
  return a;
}

int div (int a, int b)
{
  int neg = 0;
  int res =0;
  unsigned int bit = 1;  
  if (a < 0)
    {
      a = -a;
      neg = !neg;
    }
  if (b < 0)
    {
      b = -b;
      neg = !neg;
    }
  while (b < a && bit && !(b & (1L<<31)))
    {
      b <<=1;
      bit <<=1;
    }
  while (bit)
    {
      if (a >= b)
	{
	  a -= b;
	  res |= bit;
	}
      bit >>=1;
      b >>=1;
    }

  if (neg)
    res = -res;
  return res;
}


int rem (int a, int b)
{
  int neg = 0;
  int res = 0;
  unsigned int bit = 1;

  if (a < 0)
    {
      a = -a;
      neg = 1;
    }

  if (b < 0)
    b = -b;

    while (b < a && bit && !(b & (1L<<31)))
    {
      b <<=1;
      bit <<=1;
    }
  while (bit)
    {
      if (a >= b)
	  {
	  a -= b;
	  res |= bit;
	  }
      bit >>=1;
      b >>=1;
    }
  if (neg)
    a = -a;
  return a;
}
unsigned int mul (unsigned int a, unsigned int b)
{
  unsigned int r = 0;
  while (a)
    {
      if (a & 1)
	r += b;
      a >>= 1;
      b <<= 1;
    }
  return r;
}