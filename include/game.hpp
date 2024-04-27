#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include "dice.hpp"
#include "player.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include "json.hpp"

class Game {
public:
	// Constructor and Destructor
	Game();
	~Game();

	// Game methods
	void InitGame();
	void RunGame();
	void EndGame(const int winner_index);
	void PlayTurn(const int player_index);

	// Locales methods
	void InitLocales();

	// Player methods
	void InitPlayers();
	bool IsPlayerNameValid(const std::string &name) const;
	void AddPlayer(const Player &player);
	void RemovePlayer(const int player_index);

	// Prompts
	void LearnAllTiles();
	void LearnTile();

private:
	Board board_;
	std::vector<Player> players_;
	Dice dice_;
	std::string language_;
	const size_t min_players_ = 2;
	const size_t max_players_ = 8;
	const size_t min_name_length_ = 3;
	const size_t max_name_length_ = 10;

	// Locales
	nlohmann::json game_locales_;
	nlohmann::json player_locales_;

};

#endif // "GAME_HPP"