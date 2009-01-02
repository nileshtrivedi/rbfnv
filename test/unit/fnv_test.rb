require "test/unit"
require "rbfnv"

LONGKEY = "the easter island statue memorial tabernacle choir presents"

class FnvTest < Test::Unit::TestCase
  def test_fnv1_32
    assert_nothing_raised { Rbfnv }
    assert_equal Rbfnv.fnv1_32(""), 2166136261
    assert_equal Rbfnv.fnv1_32("cat"), 983016379
    assert_equal Rbfnv.fnv1_32(LONGKEY), 2223726839
  end

  def test_fnv1a_32
    assert_nothing_raised { Rbfnv }
    assert_equal Rbfnv.fnv1a_32(""), 2166136261
    assert_equal Rbfnv.fnv1a_32("cat"), 108289031
    assert_equal Rbfnv.fnv1a_32(LONGKEY), 1968151335
  end

  def test_fnv1_64
    assert_nothing_raised { Rbfnv }
    assert_equal Rbfnv.fnv1_64(""), 2216829733
    assert_equal Rbfnv.fnv1_64("cat"), 1806270427
    assert_equal Rbfnv.fnv1_64(LONGKEY), 3588698999
  end

  def test_fnv1a_64
    assert_nothing_raised { Rbfnv }
    assert_equal Rbfnv.fnv1a_64(""), 2216829733
    assert_equal Rbfnv.fnv1a_64("cat"), 216310567
    assert_equal Rbfnv.fnv1a_64(LONGKEY), 2969891175
  end
end
