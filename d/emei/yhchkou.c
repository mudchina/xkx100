inherit ROOM;
void create()
{
        set("short", "云海出口");
        set("long", @LONG
这里就是峨嵋著名的云海了，放眼望去，漫山遍野都
是云雾，根本就弄不清自己身在何出。在雾中隐隐约约有
一条瀑布夹雾而下！
LONG  );
        set("exits",([
          "north": __DIR__"pubu",
          "south": __DIR__"yunhai12",
        ]));
	set("coor/x", -6200);
	set("coor/y", -1170);
	set("coor/z", 200);
	setup();
        replace_program(ROOM);
}