// Room: /d/suzhou/.c
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "白云泉");
	set("long",@long
一股清泉顺着山麓而下，在这里汇集成一潭泉水，当地人起了一个
名字叫“白云泉”，这里的泉水如线涓涓流入一石盂中，故又名“一线
泉”或“钵盂泉”。此泉大旱不竭，唐代茶圣陆羽评为“吴中第一泉”。
诗人白居易曾赋诗吟咏“天平山上白云泉，云本无心水自闲，何必奔冲
山下去，更添波浪向人间”。泉旁设有茶室，品茗名泉者络绎不绝。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"westdown" : __DIR__"tianpingshan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 850);
	set("coor/y", -1090);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
