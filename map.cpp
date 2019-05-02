/*
 * set.cpp
 *
 *  Created on: Mar 18, 2019
 *      Author: benja
 */

#include "map.h"

// From previous task:
bool equal( const std::string& s1, const std::string& s2 )
{
  if(s1.length() != s2.length())
        return false;
    for (size_t i=0; i < s1.length(); i++) 
    {
        if(tolower(s1[i] != tolower(s2[i])))
            return false;
    }
    return true;
}

size_t hash( const std::string& s )
{
  size_t h = 0;
  for (char c:s)
    h = h*349+tolower(c);
  return h;
}

map::listofpairs::const_iterator 
map::find( const listofpairs& lst, const std::string& key )
{
   auto p = lst. begin( );
   while( p != lst. end( ) && !equal( p -> first, key ))
      ++ p;
   return p; 
}

map::listofpairs::iterator
map::find( listofpairs& lst, const std::string& key )
{
   auto p = lst. begin( );
   while( p != lst. end( ) && !equal( p -> first, key ))
      ++ p;
   return p;
}
   

bool map::contains_key( const std::string& key ) const
{
  listofpairs bucket = getbucket(key);
  return find(bucket, key)!= bucket.end();
}

bool map::insert( const std::string& key, unsigned int val )
{
  listofpairs &L = getbucket(key);
  auto it = find(L,key);
  if (it!=L.end())
    return false;
  else {
    std::pair<std::string, int> p;
    p.first=key;
    p.second=val;
    // buckets.push_back(p);
    L.push_back(p);
    map_size++;
    check_rehash();
    return true;}
}

unsigned int& map::operator[] ( const std::string& key )
{
  auto& bucket = getbucket(key);
  auto p = find(bucket,key);
  if (p!=bucket.end())
    return p->second;
  else
  {
    std::pair<std::string, int> p;
    p.first=key;
    p.second=0;
    bucket.push_back(p);
    check_rehash();
    map_size++;
    return bucket.back().second;
    //this will allow english["seven"]++;
  }
}

unsigned int& map::at( const std::string& key ){
  listofpairs& L = getbucket(key);

  auto it = find(L, key);
  if (it != L.end())
    return it->second;
  else throw std::out_of_range( "at( ): string not found" );
}


unsigned int map::at( const std::string& key ) const
{
  listofpairs L = getbucket(key);
  auto it = find(L, key);
  if (it!=L.end())
    return it->second;
  else throw std::out_of_range( "at( ): string not found" );
}

void map::rehash( size_t newbucketsize )
{
  if (newbucketsize < 4)
    newbucketsize = 4;
  std::vector<listofpairs> newbuckets{newbucketsize};

  for (size_t i = 0; i < buckets.size(); i++)
    {
        for (auto it = buckets[i].begin(); it != buckets[i].end(); it++)
        {
            size_t a = hash(it->first) % newbuckets.size();
            newbuckets[a].push_back(*it);
        }
    }
    buckets = newbuckets;
}

void map::check_rehash( )
{
        size_t a = loadfactor();
        if (a > max_load_factor)
        {
            rehash(buckets.size()*2);
        }
}

bool map::remove( const std::string& key )
{
  listofpairs& L = getbucket(key);
 //std::pair <string, int> p = find(L,key);
  auto it = find(L,key);

    if (it==L.end())
      return false;
    else
    {
      L.erase(it);
      map_size--;
      return true;
    }
}

double map::standarddev( ) const  
{
   double sum = 0.0;
   double lf = loadfactor();

   for ( const auto& l : buckets )
   {
      double dif = l.size() - lf;
      sum += dif*dif;
   }

   return sqrt( sum / buckets. size( ));
}

void map::clear( ) 
{
   for( auto& l : buckets )
      l. clear( ); 

   map_size = 0; 
}


std::ostream& map::print( std::ostream& out ) const
{
  size_t i=0;
    for (auto it = buckets.begin(); it!=buckets.end(); i++, it++)
    {
        out<<"bucket["<<i<<"]\t";
        out << "{";
        for (auto a = buckets[i].begin(); a!= buckets[i].end(); a++)
            out << a->first << " => " << a->second << " ";
        out << "}"<< std::endl;
    }
    return out;
}


std::ostream& map::printstatistics( std::ostream& out ) const
{
   out << "set size =            " << size( ) << "\n";
   out << "load factor =         " << loadfactor( ) << " ( max = " << 
                                      max_load_factor << " )\n";
   out << "standard deviation =  " << standarddev( ) << "\n";
   return out;
}


