// Room: /d/quanzhou/chenghuangmiao.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "城隍庙");
	set("long", @LONG
这是一间年代久远的小庙，里面供放着观音菩萨和土地爷，是泉州
乡间求卜问卦的场所，据说这里的签卦特灵。旁边有扇小门。
LONG );
	set("objects", ([
		__DIR__"npc/miaozhu" : 1,
	]));
	set("exits", ([
		"southeast" : __DIR__"chenghuangxiang",
		"southwest" : __DIR__"houshanmen",
	]));
	set("coor/x", 1840);
	set("coor/y", -6450);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
