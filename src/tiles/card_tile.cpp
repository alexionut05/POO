#include "tiles/card_tile.hpp"

// Constructor and Destructor
CardTile::CardTile()
{
	owner_ = "Bank";
}

CardTile::~CardTile() {}

// Print
void CardTile::Print(std::ostream &os) const
{
	os << termcolor::on_color<0, 0, 0> << termcolor::bold;
	std::string padding_left = " ";
	int padding_left_size = (k_max_tile_name_length - name_.length()) / 2;
	for (int i = 0; i < padding_left_size; i++) {
		padding_left += " ";
	}
	std::string padding_right = " ";
	int padding_right_size = k_max_tile_name_length - name_.length() - padding_left_size;
	for (int i = 0; i < padding_right_size; i++) {
		padding_right += " ";
	}

	os << padding_left << name_ << padding_right;
	os << termcolor::reset;
	os << std::endl;
}