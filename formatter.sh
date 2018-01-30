# This script attempts to format all sources to meet Moose standards
#
find . -name '*.[Ch]' | xargs clang-format -i -style=file
find . -name '*.[Ch]' | xargs sed -i '' 's/>>(/> >(/'
#not working
#find . -name '*.[Ch]' | xargs expand -t 2 {}
find . -name '*.[Chi]' -or -name '*.py' | xargs perl -pli -e 's/\s+$//'

python scripts/moose_format.py

if [[ $(find . \( -name '*.[Chi]' -or \( -name "contrib" -or -name "libmesh" -or -name ".git" \) -prune -and -type f \) -print0 | xargs -0 perl -nle 'if ($ARGV ne $oldargv && (/std::cout|std::cerr/ || /sleep\s*\(/ || ($ARGV !~ /MooseError.h/ && /print_trace/))) { print "\t$ARGV"; $oldargv=$ARGV }') ]]; then
  echo "The following files need to be checked for banned keywords:"
  find . \( -name '*.[Chi]' -or \( -name "contrib" -or -name "libmesh" -or -name ".git" \) -prune -and -type f \) -print0 | xargs -0 perl -nle 'if ($ARGV ne $oldargv && (/std::cout|std::cerr/ || /sleep\s*\(/ || ($ARGV !~ /MooseError.h/ && /print_trace/))) { print "\t$ARGV"; $oldargv=$ARGV }'

else
  echo "all good - make sure your code still compiles though!"
  echo "use the following to test:"
  echo "make clean"
  echo "make -j8"
  echo "./run_tests -j8"
  echo "./moose_tests.sh 0"
fi
