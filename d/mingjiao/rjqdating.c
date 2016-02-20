//RJQTING.C

inherit ROOM;

void create()
{
	set("short", "锐金旗大厅");
	set("long", @LONG
这是锐金旗的大厅，虽然都是练武之人，这里却布置得古色古香，
显出锐金旗的与众不同。大厅正面高悬一块牌匾，上书四个烫金大字“
锐气金风”，一百二十年前，明教与来犯的蒙古军队一场鏖战，锐金旗
力守玄天崖，死者八、九，教主亲书此匾以励教众，锐金旗以此为五旗
之首。厅中央摆有茶几，锐金旗掌旗使庄铮正襟而坐，正在读一本书卷。
LONG );
	set("exits", ([
		"south" : __DIR__"rjqyuan",
	]));
	set("objects",([
		__DIR__"npc/zhuangzheng":1,
	]));
	set("coor/x", -52020);
	set("coor/y", 870);
	set("coor/z", 50);
	setup();
}