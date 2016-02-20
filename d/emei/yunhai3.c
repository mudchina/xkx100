inherit ROOM;
void create()
{
        set("short", "云海");
        set("long", @LONG
这里就是峨嵋著名的云海了，放眼望去，漫山遍野都
是云雾，根本就弄不清自己身在何出。在雾中隐隐约约有
一条小道通向前方，还是回去吧。
LONG
        );
        set("exits", ([
  "south" : __DIR__"yunhai1"+random(3),
  "west" : __DIR__"yunhai"+random(3),
  "north" : __DIR__"yhrkou",
  "east" : __DIR__"yunhai"+random(3),
]));
        set("objects", ([
                "/clone/medicine/vegetable/lingzhi" : random(2),
        ]));
	set("coor/x", -6200);
	set("coor/y", -1180);
	set("coor/z", 200);
	setup();
        replace_program(ROOM);
}