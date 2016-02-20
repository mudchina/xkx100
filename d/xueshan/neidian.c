//      neidian.c 内殿

inherit ROOM;

void create()
{
        set("short","内殿");
        set("long",@LONG
这里是雪山寺的内殿，也是掌门人见客的地方。雪山寺的掌门人、
大轮明王、吐蕃国师鸠摩智是西域一代高僧，也是西域不世出的武林宗
师。他驻锡本寺后，雪山寺方声名远播。
LONG );
        set("exits",([
                "east" : __DIR__"tiantai",
                "west" : __DIR__"midao",
                "south" : __DIR__"zoulang3",
                "north" : __DIR__"houdian",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/jiumozhi" :1
        ]));
	set("coor/x", -70000);
	set("coor/y", -19880);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}
