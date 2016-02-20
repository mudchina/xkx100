// Room: /d/taishan/yidao2.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，
赶着大车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。不时还有两
三骑快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树
林。
LONG );
	set("exits", ([
		"southwest" : __DIR__"yidao1",
		"north"     : __DIR__"yidao3",
	]));
	set("objects",([
		__DIR__"npc/shu-sheng" : 1,
		CLASS_D("taishan")+"/tianyi" : 1,
	]));
 	set("outdoors", "jiangnan");
	set("coor/x", 400);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
