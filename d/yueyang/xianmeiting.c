// Room: /d/yueyang/xianmeiting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "仙梅亭");
	set("long", @LONG
仙梅亭位于岳阳楼的南面，相传明朝崇祯年间重修岳阳楼挖掘地基
时，掘出一块石板，石板洁白如玉，一面有一枝枯梅，若隐若现二十四
萼，纹理苍劲、如仙家所画，人们以为是仙迹，便修一小亭，立石其中
，以为纪念。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"yueyanglou1",
	]));
	set("coor/x", -1450);
	set("coor/y", -2270);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
