// /d/shenlong/npcloc/shouloc.c
// Last Modified by winder on Jul. 12 2002

// inherit SKILL;
inherit F_CLEAN_UP;

string *shoulocs = ({
	"/d/city/duchang",
	"/d/changbai/rouguan", 
	"/d/dali/yaoshou",
	"/d/foshan/yingxionglou",
	"/d/hangzhou/lingyinsi",
	"/d/changan/datiepu",
	"/d/fuzhou/laozhai",
	"/d/shaolin/shanmen",
	"/d/shenlong/tingkou",
	"/d/taishan/baihe",
	"/d/xingxiu/house",
	"/d/lingzhou/yipingate",
	"/d/xueshan/shanmen",
});

void create() { seteuid(getuid()); }

string query_loc()
{
	return shoulocs[random(sizeof(shoulocs))];
}
