#include <Python.h>

int pycall(char *py_file, char *py_func, char *text) {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;

    Py_Initialize();
    pName = PyUnicode_FromString(py_file);
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    int is_match = -1;
    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, py_func);

        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(1);
            pValue = PyUnicode_FromString(text);
            if (!pValue) {
                Py_DECREF(pArgs);
                Py_DECREF(pModule);
                fprintf(stderr, "Cannot convert argument\n");
                return -1;
            }
            PyTuple_SetItem(pArgs, 0, pValue);
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                is_match = PyLong_AsLong(pValue);
                fprintf(stderr, "Result of call: %d\n", is_match);
                Py_DECREF(pValue);
            } else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return -1;
            }
        } else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", py_func);
        }
    } else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", py_file);
        return -1;
    }
    Py_Finalize();
    return is_match;
}
