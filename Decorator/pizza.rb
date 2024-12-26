class BasePizza
  def cost
    5
  end
end

class ToppingDecorator < BasePizza
  attr_accessor :pizza

  def initialize(pizza)
    @pizza = pizza
  end

  def cost
    raise 'cost not defined'
  end
end

class Mushroom < ToppingDecorator
  def cost
    pizza.cost + 10
  end
end

class ExtraCheeze < ToppingDecorator
  def cost
    pizza.cost + 20
  end
end

pizza = BasePizza.new
pizza = Mushroom.new(pizza)
pizza = ExtraCheese.new(pizza)
p pizza.cost

