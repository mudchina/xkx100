// Room: /d/chengdu/dongjie1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这条街贯穿成都大街小巷，因这条街沿街都是有钱有势的酒楼、饭
馆，所以又称为“美食街”。这里店铺林立，商贾成群。白天这里车马
如龙，人声鼎沸，夜里星光伴月，灯火通明。南边便是成都著名的商业
中心：春熙路。北边有个客栈。
LONG	);
	set("outdoors","chengdu");
	set("exits", ([
		"west"  : __DIR__"guangchang",
		"east"  : __DIR__"dongjie2",		
		"north" : __DIR__"kedian",
		"south" : __DIR__"chunxilu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8040);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
 
