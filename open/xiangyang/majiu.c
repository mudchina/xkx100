// Room: /d/xiangyang/majiu.c 马厩
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short","马厩");
	set("long",@LONG
这里是襄阳城内唯一一家车马行。你可花钱租辆马车到各
个地方去，能节约不少体力。近来因为郭夫人----黄蓉正在组
织人力四处搜集防城材料，马夫积极响应，免费提供推车来运
送各种防城材料。
    西边马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。
LONG);
	set("outdoors", "xiangyang");
	set("no_fight", "1");
	set("no_beg", "1");
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      扬州城:  rideyz


TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"northroad2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
