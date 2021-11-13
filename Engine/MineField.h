#pragma once

#include "Graphics.h"

class MineField
{
private:
	class Tile
	{
	public:
		enum class State
		{
			Hidden,
			Flagged,
			Revealed,
		};
	public:
		void SpawnMine();
		bool HasMine() const;
		void Draw(Vei2& screenPos, Graphics& gfx) const;
		void Reveal();
		bool IsReavealed() const;
	private:
		bool hasMine = false;
		State state = State::Hidden;
	}; 
public:
	MineField(int nMines);
	void Draw(Graphics& gfx) const;
	RectI GetRect() const;
	void onRevealClick(const Vei2& screenPos);
private:
	Tile& TileAt(const Vei2& gridPos);
	const Tile& TileAt(const Vei2& gridPos) const;
	Vei2 ScreenToGrid(const Vei2& screenPos);
private:
	static int constexpr width = 20;
	static int constexpr height = 16;
	Tile field[width * height];

};