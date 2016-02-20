// Room: /yangzhou/qionghuajie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","琼花街");
	set("long",@LONG
琼花街虽是青石铺地，地面却多有裂缝，也不平整，大概琼花街是
条老街的缘故。两边的屋檐密密重重，傍河而建，数条小巷穿插其中。
行人大多匆匆而过，偶然有马蹄磕击青石的“哒哒”声。北面就是崇雅
书院，朱先生在此传授学问。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"east"   : __DIR__"kaimingqiao",
		"west"   : __DIR__"beimendajie",
		"south"  : __DIR__"chaguan",
		"north"  : __DIR__"shuyuan",
	]));
	set("coor/x", 20);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}