// Room: /d/chengdu/zongzidian.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "阿林粽子店");
	set("long", @LONG
这是一家和嘉兴“六芳斋”联营的粽子店。店主人张禽林据说是湖
北邵县的一个书生。因为爱上当地青楼的一个歌妓霍琳琳，所以弃书从
商，发誓要赚钱为爱人赎身。但是他并不是做生意的料，开店后生意一
直不好，因此在他脸上几乎看不到笑容。
LONG	);
	set("exits", ([		
		"west" : __DIR__"xiaojie1",
	]));
	set("objects", ([
		__DIR__"npc/zhangqinlin" : 1,
	]));
	set("coor/x", -8010);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

