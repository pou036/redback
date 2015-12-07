#!/bin/bash

function tab_files()
{
  find . \( -name '*.[Chi]' -or -name '*.py' -or \( -name "crow" -or -name "contrib" -or -name "libmesh" -or -name ".git" \) -prune -and -type f \) -print0 | xargs -0 perl -nle 'if ($ARGV   ne $oldargv && /\t/) { print "\t$ARGV"; $oldargv=$ARGV }'
}

function banned_keywords()
{
  find . \( -name '*.[Chi]' -or \( -name "contrib" -or -name "libmesh" -or -name ".git" \) -prune -and -type f \) -print0 | xargs -0 perl -nle 'if ($ARGV ne $oldargv && (/std::cout|std::cerr/ || /sleep\s*\(/ || ($ARGV !~ /MooseError.h/ && /print_trace/))) { print "\t$ARGV"; $oldargv=$ARGV }'
}

function style_files()
{
  find . \( -name '*.[Ch]' -or \( -name "contrib" -or -name "libmesh" -or -name ".git" \) -prune -and -type f \) -print0 | xargs -0 perl -nle 'if ($ARGV ne $oldargv &&   (/\bfor\(/ || /\bif\(/ || /\bwhile\(/ || /\bswitch\(/)) { print "\t$ARGV"; $oldargv=$ARGV }'
}

function whitespace_files()
{
  find . \( -name '*.[Chi]' -or -name '*.py' -or \( -name "crow" -or -name "contrib" -or -name "libmesh" -or -name ".git" \) -prune -and -type f \) -print0 | xargs -0 perl -nle 'if ($ARGV ne $oldargv && /\s+$/) { print "\t$ARGV"; $oldargv=$ARGV }'
}
ARGUMENT="$1"

case "$ARGUMENT" in

  (1)
    tab_files
    echo "tab_files" ;;
  (2)
    banned_keywords
    echo "banned_keywords";;
  (3)
    style_files
    echo "style_files";;
  (4)
    whitespace_files
    echo "whitespace_files";;
  (0)
    tab_files
    banned_keywords
    style_files
    whitespace_files
    echo "all_tests";;
esac
