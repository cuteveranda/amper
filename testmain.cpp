void PathsToStream(const Paths64& paths, std::ostream& stream)
{
  for (Paths64::const_iterator paths_it = paths.cbegin(); 
    paths_it != paths.cend(); ++paths_it)
  {
    //watch out for empty paths
    if (paths_it->cbegin() == paths_it->cend()) continue;
    Path64::const_iterator path_it, path_it_last;
    for (path_it = paths_it->cbegin(), path_it_last = --paths_it->cend();
      path_it != path_it_last; ++path_it)
      stream << *path_it << ", ";
    stream << *path_it_last << endl;
  }
}

static bool GetInt(string::const_iterator& s_it,
  const string::const_iterator& it_end, int64_t& value)
{
  value = 0;
  while (s_it != it_end && *s_it == ' ') ++s_it;
  if (s_it == it_end) return false;
  bool is_neg = (*s_it == '-');
  if (is_neg) ++s_it;
  string::const_iterator s_it2 = s_it;
  while (s_it != it_end && *s_it >= '0' && *s_it <= '9')
  {
    value = value * 10 + static_cast<int64_t>(*s_it++) - 48;
  }
  if (s_it == s_it2) return false; //no value
  //trim trailing space and a comma if present
  while (s_it != it_end && *s_it == ' ') ++s_it;
  if (s_it != it_end && *s_it == ',') ++s_it;
  if (is_neg) value = -value;
  return true;
}
