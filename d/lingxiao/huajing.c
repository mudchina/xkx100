// Room: /d/lingxiao/huajing.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","花径");
	set("long",@LONG 
这是一条种满了各色梅花的花径。在小径两边，梅花飘香，梅萼生
寒。悠然而赏鉴，梅枝蜿蜒，梅干崎岖，古朴飘逸，兼而有之。梅树枝
干以枯残丑拙为贵，梅花梅萼以繁密浓聚为尚，此处之景，可谓得矣。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"qianyuan",
		"up"   : __DIR__"feihua",  
	]));
	set("objects", ([
	       __DIR__"npc/xuehe" : 1,
	       __DIR__"obj/mei" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8880);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

