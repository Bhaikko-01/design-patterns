# # interface
# module MoveStrat
#   def move
#     raise "Implement"
#   end
# end

# class NormalWalk
#   include MoveStrat

#   def move
#     puts "Normal Walk"
#   end
# end

# class MoonWalk
#   include MoveStrat

#   def move
#     puts "Moon Walk"
#   end
# end

# class FloatingWalk
#   include MoveStrat
# end

# class Character
#   attr_accessor :walk_strat

#   def initialize(walk_strat)
#     @walk_strat = walk_strat
#   end

#   def move
#     @walk_strat.move
#   end
# end

# normalWalk = NormalWalk.new
# moonWalk = MoonWalk.new

# c = Character.new(normalWalk)
# c.move

# c.walk_strat = moonWalk
# c.move

module VehicleParkingFareStrat
  def calculate
  end
end

class CarParkingFareStrat
  include VehicleParkingFareStrate

  def calculate(vechile)
    # $40/hr
  end
end

class BikeParkingFareStrat
  include VehicleParkingFareStrate

  def calculate(vehicle)
    # $20/hr
  end
end

class Bike
end

class Car
  def fare_strat

  end
  
end

class ParkingFareCalculator
  def calculate_fare(calc_strategy, vehicle)
    calc_stragey.calculate_fare(vehicle)
  end
end

c1 = Car.new
c2 = Car.new
c3 = Car.new

pfc = ParkingFareCalculator.new
pfc.calculate_fare(CarParkingFareStrat.new, Car.new)
pfc.calculate_fare(BikeParkingFareStrat.new, Bike.new)
