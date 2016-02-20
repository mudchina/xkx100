// Room: /heizhao/shanding.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山顶");
	set("long", @LONG
山峰顶上是块平地，开垦成二十来亩山田，种着禾稻，一柄锄
头抛在田边，一个耕夫上身赤膊，腿上泥污及膝，正在摆布山坡上
一头仰天卧在一块岩石上，四足挣扎，站不起来，昂首哀鸣的大黄
牛。
LONG );
	set("outdoors", "taoyuan");
	set("objects", ([
		CLASS_D("dali")+"/yideng/gen" : 1,
		"/d/wudang/npc/cow" : 1,
	]));
	set("exits", ([
		"down"     : __DIR__"shanlu10",
		"northup"  : __DIR__"shiliang1",
	]));
	set("coor/x", -5020);
	set("coor/y", -1260);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}