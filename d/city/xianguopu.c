// Room: /yangzhou/xianguopu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","彭记鲜果铺");
	set("long",@LONG
人说彭记是一家扬州城的老字号，扬州城内的大户人家采买鲜果都
是来此，因而店内人来人往，极为热闹，小二忙来忙去招呼着买家。门
楣上有一烫金匾额，架上的各色鲜果飘出的清香沁人心脾，令人垂涎欲
滴。边上的躺椅上有个胖子，似乎是帐房先生。
LONG );
	set("exits", ([
		"west" : __DIR__"caiyidongjie",
	]));
	set("objects", ([
		__DIR__"npc/pengbaoxian" : 1,
	]));
	set("coor/x", 70);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}