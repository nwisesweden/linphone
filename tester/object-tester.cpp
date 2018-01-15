/*
 * object-tester.cpp
 * Copyright (C) 2017  Belledonne Communications SARL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "object/object-p.h"
#include "object/object-p.h"

#include "liblinphone_tester.h"
#include "tester_utils.h"

// =============================================================================

using namespace std;

using namespace LinphonePrivate;

// -----------------------------------------------------------------------------

#define CHECK_SIGNAL(NAME, INDEX) \
	static_assert(L_INTERNAL_SIGNAL_INDEX(NAME, __LINE__) == INDEX, "Bad signal index.");
class TestObjectPrivate : public ObjectPrivate {
public:
};

class TestObject : public Object {
	L_OBJECT(TestObject);

public:
	TestObject () : Object(*new TestObjectPrivate) {}

	L_SIGNAL(signal1, (int, float), toto, tata); CHECK_SIGNAL(signal1, 0);
	L_SIGNAL(signal2, (bool, float, int), a, b, c); CHECK_SIGNAL(signal2, 1);

	static void toto () {
		lMetaSignals(
			LinphonePrivate::Private::MetaObjectCounter<5>(),
			static_cast<lType **>(nullptr)
		);

	}

private:
	L_DECLARE_PRIVATE(TestObject);
};

// -----------------------------------------------------------------------------

static void check_object_creation () {
	TestObject *object = new TestObject();

	TestObject::toto();
	delete object;
}

test_t object_tests[] = {
	TEST_NO_TAG("Check object creation", check_object_creation)
};

test_suite_t object_test_suite = {
	"Object", NULL, NULL, liblinphone_tester_before_each, liblinphone_tester_after_each,
	sizeof(object_tests) / sizeof(object_tests[0]), object_tests
};