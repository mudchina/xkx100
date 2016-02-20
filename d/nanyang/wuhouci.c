// Room: /d/nanyang/wuhouci.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;
void create()
{
	set("short","武侯祠");
	set("long",@LONG
武侯祠乃为三国时期的著名人物，家喻户晓的诸葛亮而建，相传这
里即是他的家乡。进得山门，但见松柏森森，环境幽静，院子正中一间
八卦亭，彩绘流檐，设计精巧。两侧分别是小巧的钟，鼓楼，相互呼应
；北面是正殿。
LONG);
	set("exits",([
		"southwest" : __DIR__"dajie2",
		"north"     : __DIR__"zhengdian",
	]));
	set("outdoors","nanyang");
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
