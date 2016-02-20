// Room: /d/taishan/yidao1.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，
赶着大车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。不时还有两
三骑快马从身边飞驰而过，扬起一路尘埃。马上的人个个身着劲装，衣
甲鲜明，有的还随身佩带着刀剑，看来都是些习武的江湖人。道路两旁
是整整齐齐的杨树林。
LONG );
	set("exits", ([
		"west" : __DIR__"yidao",
		"northeast" : __DIR__"yidao2",
		"southeast" : "/d/jiaxing/jnroad1",
	]));
	set("objects",([
		__DIR__"npc/tangzi" : 2,
                "/d/quanzhou/npc/hai" : 1,
                "/d/city/npc/xiaoguiz" : 1,
	]));
	set("outdoors", "jiangnan");
	set("coor/x", 300);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
