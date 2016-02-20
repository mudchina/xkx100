// Room: /d/songshan/fawangsi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "法王寺");
	set("long", @LONG
法王寺在嵩山玉柱峰下，隐约于茂密松林中，背后是太室，两边有
峻岭，好象一把椅子，古刹位于中间。法王寺建于东汉明帝永平十四年
（公元七十一年），是佛教传入中国后建造最早的寺院，是汉明帝专为
印度高僧摄摩腾和竺法兰译经传教而敕建的，成为中国第一所菩提道场，
规模宏大，结构严谨，殿堂楼阁，金碧辉煌。
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao4",
		"northeast" : __DIR__"shandao5",
		"northup"   : __DIR__"tayuan",
		"west"      : __DIR__"yuetai",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/gao": 1,
		__DIR__"npc/dizi" : 1,
	]));
	set("coor/x", -30);
	set("coor/y", 810);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
