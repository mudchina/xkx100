//Room: /d/foshan/street4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","佛山镇街");
	set("long",@LONG
凤家在佛山是首屈一指的大户，凤家的家丁常牵着狼狗鱼肉乡
里。一般的百姓只好忍辱偷生。一条大街横亘东西。路南一家三开
间门面的大酒楼，招牌上写着“英雄楼”三个金漆大字，两边敞着
窗户，酒楼里刀杓乱响，酒肉香气阵阵喷出。路北有家烧饼油条铺，
里面传出阵阵油烟香气。
LONG);
	set("objects", ([
	    __DIR__"npc/wolfdog": 2,
	    __DIR__"npc/zhongxiaoer": 1,
	    __DIR__"npc/zhongsisao": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "north" : __DIR__"youtiaopu",
	    "south" : __DIR__"yingxionglou",
	    "west"  : __DIR__"street3",
	    "east"  : __DIR__"street5",
	]));
	set("coor/x", -1300);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
