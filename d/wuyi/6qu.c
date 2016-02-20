// Room: /d/wuyi/6qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "六曲");
	set("long", @LONG
溪流依山而流，溪水清澈见底，水中寸许长的游鱼的影子印在溪
底鹅卵石上，闪动着晶莹的水波。两岸树绿竹翠，奇峰突兀。朱熹《
九曲棹歌》曰：“……六曲苍屏饶碧湾，茆茨终日掩柴关。客来倚棹
岩花落，猿鸟不惊春意闲。……”
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"7qu",
		"southup"   : __DIR__"xiangshengyan",
		"southeast" : __DIR__"5qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1350);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

