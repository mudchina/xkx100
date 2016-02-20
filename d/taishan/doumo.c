// Room: /d/taishan/doumo.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "斗母宫");
	set("long", @LONG
斗母宫为泰山古道观。宫东临龙泉峰，又有龙泉水自西北山峡绕宫
东注中溪，故又名龙泉观。宫筑于盘道旁深壑绝壁之上，深秀幽雅。清
康熙初年尼姑住持，祀北斗众星之母，遂更名斗姥宫，又名妙香院，俗
称斗母宫。正殿原祀斗母神，俗称千手千眼佛。今置地藏菩萨铜像。
    上了前面这一段山路，游人一般都会在这里稍为休息。这里的地势
已经比泰山邻近的徂徕山为高，从这里往东上去便是石经峪。
LONG );
	set("exits", ([
		"southeast" : __DIR__"feilong",
		"southwest" : __DIR__"fengyue",
		"northup"   : __DIR__"tianshen",
		"eastup"    : __DIR__"jingshi",
		"southdown" : __DIR__"taohua",
	]));
	set("objects",([
		__DIR__"npc/jian-ke" : 1,
	]));
	set("coor/x", 400);
	set("coor/y", 600);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
