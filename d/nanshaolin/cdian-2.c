// Room: /d/nanshaolin/cdian-2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "西侧殿");
	set("long", @LONG
这里是西侧殿。房间四周悬挂着达摩祖师、观音大士的画像，以及
一些寺内元老的字画。地下散乱地放着许多蒲团，木鱼等。看来此处是
本派弟子打坐修行之所。几位年轻僧人正肃容入定，看来已颇得禅宗三
昧。
LONG);
	set("exits", ([
		"east" : __DIR__"gchang-2",
	]));
	set("objects",([
		WEAPON_DIR+"hammer/muchui" : 1,
	]));
	set("coor/x", 1800);
	set("coor/y", -6290);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

