//Room: /d/yangzhou/majiu1.c 马厩
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","马厩");
	set("long",@LONG
这是客寓后的马厩，常年供应新鲜草料。扬州民风淳朴，马夫们会
把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺
候到客人上路。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。
    马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
	set("outdoors", "yangzhouw");
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/zaohongma": 1,
		__DIR__"npc/huangbiaoma": 1,
		__DIR__"npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      北京城:  ridebj
          苏州城:  ridesz
          杭州城:  ridehz
          福州城:  ridefz
          无锡城:  ridewx
          成都城:  ridecd
          长安城:  rideca
          襄阳城:  ridexy
          开封城:  ridekf
          延平城:  rideyp
          永登城:  rideyd
          武昌镇:  ridewc
          佛山镇:  ridefs
          峨嵋山:  rideem

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"west" : __DIR__"kedian",
		"up"   : SHOP_DIR"yangzhou_shop",
	]));
	set("coor/x", 21);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
