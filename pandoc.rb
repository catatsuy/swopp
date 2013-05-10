PANDOC   = "pandoc.my"
OPTS_SET = "-f markdown -t latex"

# files = `ls *_md.tex`

Dir::glob("./*_md.tex") do |file|
  output = file.sub(/_md\.tex$/, ".tex")
  `#{PANDOC} #{OPTS_SET} #{file} -o #{output}`
end

# files.each do |file|
#   file.chomp!
#   
# end
