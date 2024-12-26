# # hell
# module DatabaseInterface
#   def query(query_to_run)
#     raise StandardException("Abstract method")
#   end
# end


# class PostgresDb
#   include DatabaseInterface

#   def query(query_to_run)

#   end
# end

# class MySQLDb
#   include DatabaseInterface

#   def query(query_to_run)

#   end
# end

# db = MySQL.new
# db.query("hello")

puts "Start"

i = 0
while i < 100000000
  i+=1
end

puts "End"
