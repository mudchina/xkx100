// /d/shenlong/npcloc/zhangloc.c
// Last Modified by winder on Jul. 12 2002

// inherit SKILL;
inherit F_CLEAN_UP;

string *zhanglocs = ({
	"/d/guanwai/tuwu",
	"/d/city/yamen",
	"/d/dali/tusifu",
	"/d/emei/dxdian",
	"/d/foshan/eastgate",
	"/d/hangzhou/kedian",
	"/d/huashan/siguoya",
	"/d/jiaxing/tieqiang",
	"/d/huanghe/gulang",
	"/d/quanzhou/kedian",
	"/d/nanyang/ruzhou",
	"/d/shenlong/qianlong",
	"/d/taishan/shengxian",
	"/d/wudang/slxl1",
	"/d/xingxiu/yili",
	"/d/lingzhou/chema",
	"/d/xueshan/sroad9",
});

void create() { seteuid(getuid()); }

string query_loc()
{
	return zhanglocs[random(sizeof(zhanglocs))];
}
