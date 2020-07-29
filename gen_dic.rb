
class Increment

  def initialize(len, limit, initlen=1)
    @len = len
    @limit = limit - 1
    @array = Array.new
    initlen.times {|x|
      @array[x] = 0
    }
    @array[0] = nil
  end

  def inc(n)
    #桁数がlimitを超えていたら
    return nil if n > @limit

    #今の桁を足す 
    if @array[n].nil? #|| @array[n].empty?
      @array[n] = 0
      return @array
    else
      @array[n] += 1 
    end
    #n桁目が@lenを超えていたら今の桁を0にして、次の桁をincrement
    if @array[n] >= @len
      @array[n] = 0
      a = inc(n+1)
      #桁数がlimitを超えていたらnilを返す
      return nil if a.nil?
    end
    return @array
  end
end


if __FILE__ == $0
  if ARGV.size < 2 
    puts "ruby #{__FILE__} <start_len> <end_len>"
    exit
  end
  start_len = ARGV[0].to_i
  end_len = ARGV[1].to_i
  @str = %Q{0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_=+\|`~[]\{\};:'",<.>/?}
  size = @str.length
  s = Increment.new(size, end_len, start_len)

  while 1
    ary = s.inc(0)
    break if ary.nil?
    ary.reverse_each { |x|
      print @str[x]
    }
    print "\n"
  end
end
